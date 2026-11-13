; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(assert
 (let ((?x53 (bvmul arg0_0 arg0_1)))
(let ((?x4053 (bvmul (_ bv4294967295 32) ?x53)))
(let ((?x768 (bvmul arg0_0 arg0_4)))
(let ((?x84 (bvadd ?x768 ?x4053)))
(and (distinct ?x84 (_ bv0 32)) true))))))
(check-sat)
