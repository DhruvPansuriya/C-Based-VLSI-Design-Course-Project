; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_0 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x510852 (bvmul arg0_0 arg1_0)))
(let ((?x585638 (bvmul (_ bv4294967295 32) ?x510852)))
(let ((?x561686 (bvmul arg0_0 arg1_1)))
(let ((?x15899 (bvadd ?x561686 ?x585638)))
(and (distinct ?x15899 (_ bv0 32)) true))))))
(check-sat)
