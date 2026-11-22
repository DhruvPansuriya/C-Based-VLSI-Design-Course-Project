; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_59 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg1_31 () (_ BitVec 32))
(assert
 (let ((?x75305 (bvmul arg0_3 arg1_59)))
(let ((?x75939 (bvmul (_ bv4294967295 32) ?x75305)))
(let ((?x64049 (bvmul arg0_3 arg1_31)))
(let ((?x72707 (bvadd ?x64049 ?x75939)))
(and (distinct ?x72707 (_ bv0 32)) true))))))
(check-sat)
