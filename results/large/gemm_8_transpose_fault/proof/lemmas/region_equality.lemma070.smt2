; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_8 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x75292 (bvmul arg0_8 arg1_8)))
(let ((?x54243 (bvmul (_ bv4294967295 32) ?x75292)))
(let ((?x45117 (bvmul arg0_8 arg1_1)))
(let ((?x70188 (bvadd ?x45117 ?x54243)))
(and (distinct ?x70188 (_ bv0 32)) true))))))
(check-sat)
