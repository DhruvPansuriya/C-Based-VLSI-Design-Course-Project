; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_0 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x19826 (bvmul arg0_4 arg1_0)))
(let ((?x479548 (bvmul (_ bv4294967295 32) ?x19826)))
(let ((?x383981 (bvmul arg0_4 arg1_1)))
(let ((?x424796 (bvadd ?x383981 ?x479548)))
(and (distinct ?x424796 (_ bv0 32)) true))))))
(check-sat)
